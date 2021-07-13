-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pshm_create

write: ## run write
	$(call gcc,$(CURRENT_DIR)/write.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pshm_write

read: ## run read
	$(call gcc,$(CURRENT_DIR)/read.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pshm_read
	make run

unlink: ## run unlink
	$(call gcc,$(CURRENT_DIR)/unlink.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/pshm_unlink
