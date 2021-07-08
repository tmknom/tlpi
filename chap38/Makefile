-include ../Makefile

dump: ## run dump
	$(call gcc,$(CURRENT_DIR)/dump.c)
	$(call exec)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/dump

login: dump ## run login
	$(call gcc,$(CURRENT_DIR)/login.c)
	make run
