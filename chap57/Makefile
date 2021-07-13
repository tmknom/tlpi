-include ../Makefile

us_xfr: ## run us_xfr
	$(call gcc,$(CURRENT_DIR)/us_xfr_sv.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/us_xfr_sv
	$(call gcc,$(CURRENT_DIR)/us_xfr_cl.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/us_xfr_cl
	make run

ud_ucase: ## run ud_ucase
	$(call gcc,$(CURRENT_DIR)/ud_ucase_sv.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/ud_ucase_sv
	$(call gcc,$(CURRENT_DIR)/ud_ucase_cl.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/ud_ucase_cl
	make run
