-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pmsg_create
	$(call exec,-cx /mq)
