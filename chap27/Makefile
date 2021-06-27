-include ../Makefile

envargs: ## run envargs
	$(call gcc,$(CURRENT_DIR)/envargs.c)
	$(call exec)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/envargs

execve: envargs ## run execve
	$(call gcc,$(CURRENT_DIR)/execve.c)
	$(call exec,bin/envargs)

execlp: ## run execlp
	$(call gcc,$(CURRENT_DIR)/execlp.c)
	$(call exec,echo)

execle: ## run execle
	$(call gcc,$(CURRENT_DIR)/execle.c)
	$(call exec,/bin/echo)

execl: ## run execl
	$(call gcc,$(CURRENT_DIR)/execl.c)
	$(call exec)

closeonexec: ## run closeonexec
	$(call gcc,$(CURRENT_DIR)/closeonexec.c)
	$(call exec)
	$(call exec,invalid)
