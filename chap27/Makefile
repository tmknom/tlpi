-include ../Makefile

envargs: ## run envargs
	$(call gcc,$(CURRENT_DIR)/envargs.c)
	$(call exec)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/envargs

execve: envargs ## run execve
	$(call gcc,$(CURRENT_DIR)/execve.c)
	$(call exec,bin/envargs)
