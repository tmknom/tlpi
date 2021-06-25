-include ../Makefile

read: ## run read
	$(call gcc,$(CURRENT_DIR)/read.c)
	$(call exec)

nanosleep: ## run nanosleep
	$(call gcc,$(CURRENT_DIR)/nanosleep.c)
	$(call exec,10 0)

signal: ## run signal
	$(call gcc,$(CURRENT_DIR)/signal.c)
	$(call exec,2:5)

thread: ## run thread
	$(call gcc,$(CURRENT_DIR)/thread.c)
	$(call exec,2:5)

timerfd: ## run timerfd
	$(call gcc,$(CURRENT_DIR)/timerfd.c)
	$(call exec,1:1 100)
