-include ../Makefile

free: ## run free
	$(call gcc,$(CURRENT_DIR)/free.c)
	$(call exec, 1000 10240 2)
	$(call exec, 1000 10240 1 1 999)
	$(call exec, 1000 10240 1 500 1000)
