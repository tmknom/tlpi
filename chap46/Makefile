-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svmsg_create

send: ## run send
	$(call gcc,$(CURRENT_DIR)/send.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svmsg_send

receive: create send ## run receive
	$(call gcc,$(CURRENT_DIR)/receive.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svmsg_receive
	make run

rm: ## run rm
	$(call gcc,$(CURRENT_DIR)/rm.c)
	make run

chqbytes: ## run chqbytes
	$(call gcc,$(CURRENT_DIR)/chqbytes.c)
	make run
