-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_create
	$(call exec,-cx /mq)

getattr: ## run getattr
	$(call gcc,$(CURRENT_DIR)/getattr.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_getattr

unlink: ## run unlink
	$(call gcc,$(CURRENT_DIR)/unlink.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_unlink

send: ## run send
	$(call gcc,$(CURRENT_DIR)/send.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_send

receive: ## run receive
	$(call gcc,$(CURRENT_DIR)/receive.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_receive
	make run

signal: ## run signal
	$(call gcc,$(CURRENT_DIR)/signal.c)
	make run

thread: ## run thread
	$(call gcc,$(CURRENT_DIR)/thread.c)
	make run
