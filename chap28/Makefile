-include ../Makefile

acct_on: ## run acct_on
	$(call gcc,$(CURRENT_DIR)/acct_on.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/acct_on

acct_view: acct_on ## run acct_view
	$(call gcc,$(CURRENT_DIR)/acct_view.c)
	make run
