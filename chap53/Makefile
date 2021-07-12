-include ../Makefile

create: ## run create
	$(call gcc,$(CURRENT_DIR)/create.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/psem_create

unlink: ## run unlink
	$(call gcc,$(CURRENT_DIR)/unlink.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/psem_unlink

wait: ## run wait
	$(call gcc,$(CURRENT_DIR)/wait.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/psem_wait

post: ## run post
	$(call gcc,$(CURRENT_DIR)/post.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/psem_post

getvalue: ## run getvalue
	$(call gcc,$(CURRENT_DIR)/getvalue.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/psem_getvalue
