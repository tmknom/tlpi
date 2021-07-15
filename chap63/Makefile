-include ../Makefile

select: ## run select
	$(call gcc,$(CURRENT_DIR)/select.c)
	make run

poll: ## run poll
	$(call gcc,$(CURRENT_DIR)/poll.c)
	make run

sigio: ## run sigio
	$(call gcc,$(CURRENT_DIR)/sigio.c)
	$(call exec)
