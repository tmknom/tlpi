-include ../Makefile

setsid: ## run setsid
	$(call gcc,$(CURRENT_DIR)/setsid.c)
	$(call exec)

sighup: ## run sighup
	$(call gcc,$(CURRENT_DIR)/sighup.c)
	$(call exec)

disc: ## run disc
	$(call gcc,$(CURRENT_DIR)/disc.c)
	$(call exec, d s s)
