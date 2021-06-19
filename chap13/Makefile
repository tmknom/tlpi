-include ../Makefile

direct: ## run direct
	$(call gcc,$(CURRENT_DIR)/direct.c)
	$(call exec, Makefile 512)
	$(call exec, Makefile 4096 8192 512)
