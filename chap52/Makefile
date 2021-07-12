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
