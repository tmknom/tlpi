-include ../Makefile

id_echo: ## run id_echo
	$(call gcc,$(CURRENT_DIR)/id_echo_sv.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/id_echo_sv
	$(call gcc,$(CURRENT_DIR)/id_echo_cl.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/id_echo_cl
	make run
