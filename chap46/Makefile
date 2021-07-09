-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	$(call exec,-p)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svmsg_create

send: ## run send
	$(call gcc,$(CURRENT_DIR)/send.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svmsg_send
	make run
