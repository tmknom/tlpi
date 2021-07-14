-include ../Makefile

i6d_ucase: ## run i6d_ucase
	$(call gcc,$(CURRENT_DIR)/i6d_ucase_sv.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/i6d_ucase_sv
	$(call gcc,$(CURRENT_DIR)/i6d_ucase_cl.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/i6d_ucase_cl
	make run
