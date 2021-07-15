-include ../Makefile

is_echo: ## run is_echo
	$(call gcc,$(CURRENT_DIR)/is_echo_sv.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/is_echo_sv
	$(call gcc,$(CURRENT_DIR)/is_echo_cl.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/is_echo_cl
	make run

socknames: ## run socknames
	$(call gcc,$(CURRENT_DIR)/socknames.c)
	make run
