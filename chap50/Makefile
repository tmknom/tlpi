-include ../Makefile

mprotect: ## run mprotect
	$(call gcc,$(CURRENT_DIR)/mprotect.c)
	$(call exec)

memlock: ## run memlock
	$(call gcc,$(CURRENT_DIR)/memlock.c)
	$(call exec,32 8 3)
