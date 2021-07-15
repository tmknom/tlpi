-include ../Makefile

intr: ## run intr
	$(call gcc,$(CURRENT_DIR)/intr.c)
	make run

no_echo: ## run no_echo
	$(call gcc,$(CURRENT_DIR)/no_echo.c)
	$(call exec)

sigwinch: ## run sigwinch
	$(call gcc,$(CURRENT_DIR)/sigwinch.c)
	$(call exec)

tty: ## run tty
	$(call gcc,$(CURRENT_DIR)/tty.c)
	make run
