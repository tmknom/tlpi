-include ../Makefile

ouch: ## run ouch
	$(call gcc,$(CURRENT_DIR)/ouch.c)
	$(call exec)

intquit: ## run intquit
	$(call gcc,$(CURRENT_DIR)/intquit.c)
	$(call exec)

kill: ## run kill
	$(call gcc,$(CURRENT_DIR)/kill.c)
	$(call exec,1 0)
	$(call exec,2 17)

sender: ## run sender
	$(call gcc,$(CURRENT_DIR)/sender.c)
	make run
