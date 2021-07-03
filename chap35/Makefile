-include ../Makefile

setpriority: ## run setpriority
	$(call gcc,$(CURRENT_DIR)/setpriority.c)
	$(call exec,p 0 25)
	$(call exec,p 0 15)
