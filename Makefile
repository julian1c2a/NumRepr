.PHONY: clean All

All:
	@echo "----------Building project:[ NumericRepresentations - Debug ]----------"
	@"$(MAKE)" -f  "NumericRepresentations.mk"
clean:
	@echo "----------Cleaning project:[ NumericRepresentations - Debug ]----------"
	@"$(MAKE)" -f  "NumericRepresentations.mk" clean
