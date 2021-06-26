-include ../Makefile

wait: ## run wait
	$(call gcc,$(CURRENT_DIR)/wait.c)
	$(call exec,7 1 4)

status: ## run status
	$(call gcc,$(CURRENT_DIR)/status.c)
	$(call exec,23)

zombie: ## run zombie
	$(call gcc,$(CURRENT_DIR)/zombie.c)
	$(call exec)
