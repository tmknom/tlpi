SHELL=/bin/bash
.DEFAULT_GOAL := help

# https://gist.github.com/tadashi-aikawa/da73d277a3c1ec6767ed48d1335900f3
.PHONY: $(shell grep --no-filename -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | sed 's/://')

WORK_PATH := /work
BINARY_PATH := $(WORK_PATH)/bin/main
LIB_PATH := $(WORK_PATH)/lib/libtlpi.a
PROJECT_ROOT := $$(git rev-parse --show-toplevel)
CURRENT_DIR := $(WORK_PATH)/$(notdir $(CURDIR))

define gcc
	docker run --rm -w /work -v $(PROJECT_ROOT):/work -u docker debian:gcc gcc -lrt -pthread -Wall -O0 -g -o $(BINARY_PATH) ${1} $(LIB_PATH)
endef

define optimized_gcc
	docker run --rm -w /work -v $(PROJECT_ROOT):/work -u docker debian:gcc gcc -lrt -Wall -o $(BINARY_PATH) ${1} $(LIB_PATH)
endef

define exec
	docker run -it --rm --cap-add=ALL --security-opt="seccomp=unconfined" --cpuset-cpus 0 --cpu-quota 20000 -h localhost -w /work -v $(PROJECT_ROOT):/work -u docker debian:gcc $(BINARY_PATH) ${1}
endef

# Phony Targets

docker: ## docker build
	docker build -t debian:gcc docker/

clean: ## Clean
	rm -f $(PROJECT_ROOT)/bin/main
	rm -f $(PROJECT_ROOT)/bin/*.o
	rm -f $(PROJECT_ROOT)/lib/*.o
	rm -f $(PROJECT_ROOT)/lib/*.a

run: ## docker run
	docker run -it --rm -h localhost --cap-add=ALL --security-opt="seccomp=unconfined" -w /work -v $(PROJECT_ROOT):/work debian:gcc /bin/bash || true

lib: clean ## compile lib
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o error_functions.o error_functions.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o get_num.o get_num.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o ugid_functions.o ugid_functions.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o curr_time.o curr_time.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o file_perms.o file_perms.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o signal_functions.o signal_functions.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o itimerspec_from_str.o itimerspec_from_str.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o print_wait_status.o print_wait_status.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o print_rlimit.o print_rlimit.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o become_daemon.o become_daemon.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o region_locking.o region_locking.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o read_line.o read_line.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o inet_sockets.o inet_sockets.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc gcc -Wall -Og -c -o tty_functions.o tty_functions.c
	docker run --rm -w /work -v $(PROJECT_ROOT)/lib:/work debian:gcc ar -r libtlpi.a error_functions.o get_num.o ugid_functions.o curr_time.o file_perms.o signal_functions.o itimerspec_from_str.o print_wait_status.o print_rlimit.o become_daemon.o region_locking.o read_line.o inet_sockets.o tty_functions.o
	mkdir -p $(PROJECT_ROOT)/bin

# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
