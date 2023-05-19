CC=gcc
TARGET=APP_RGR
BUILD_DIR=build
#BUILD_DIR=~/RGR/RGR_SysSofEmbSys_2023/RGR_system_software
LIBRARY_TYPE?=static
#LIBRARY_TYPE=shared

# Список об'єктних файлів, які потрібно скомпілювати
#OBJECTS=$(addprefix $(BUILD_DIR)/, main.o Add_matrix.o Multiply_matrix.o Subtract_matrix.o)
ifeq ($(LIBRARY_TYPE), static)
	OBJECTS=$(addprefix $(BUILD_DIR)/, main.o libfunc.a)
else
	OBJECTS=$(addprefix $(BUILD_DIR)/, main.o libfunc.so)
endif

# Компілювати зі статичною або спільною бібліотекою
ifeq ($(LIBRARY_TYPE), static)
	LIBRARY_FLAG=-static
	LIBRARY_NAME=libfunc.a
	LIBRARY_F=
else
	LIBRARY_FLAG=-shared
	LIBRARY_NAME=libfunc.so
	LIBRARY_F=-fPIC
endif

# Задаємо змінні середовища для компілятора та лінкера
CFLAGS ?=
LDFLAGS=-lm

# Створення виконуваного файлу
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS) | $(BUILD_DIR)/$(LIBRARY_NAME)
ifeq ($(LIBRARY_TYPE), static)
	$(CC) $(OBJECTS) -lfunc -L./$(BUILD_DIR) $(LDFLAGS) -o $@
else
	$(CC) $(LDFLAGS) $(OBJECTS) -lfunc -L./$(BUILD_DIR) -o $@
endif

# Компіляція коду
$(BUILD_DIR)/main.o: main.c Discriminant.h Roots.h | $(BUILD_DIR)
	$(CC) -c $< $(CFLAGS) -o $@

$(BUILD_DIR)/Discriminant.o: Discriminant.c Discriminant.h | $(BUILD_DIR)
	$(CC) $(LIBRARY_F) -c $< $(CFLAGS) -o $@

$(BUILD_DIR)/Roots.o: Roots.c Roots.h | $(BUILD_DIR)
	$(CC) $(LIBRARY_F) -c $< $(CFLAGS) -o $@


# Створення бібліотеки
$(BUILD_DIR)/$(LIBRARY_NAME): $(addprefix $(BUILD_DIR)/, Discriminant.o Roots.o)
ifeq ($(LIBRARY_TYPE), static)
	ar rcs $@ $^
else
	$(CC) $(LIBRARY_FLAG) -Wl,-soname,libfunc.so -o $(BUILD_DIR)/libfunc.so $^ -lc
endif


# Ціль для статичного аналізу коду
.PHONY: check

check:
ifeq ($(CHECK_TOOL), cppcheck)
	$(CHECK_TOOL) *.c *.h
	@echo "has bin checked with cppcheck!"
else ifeq ($(CHECK_TOOL), checkpatch)
	perl checkpatch.pl --no-tree --ignore NEW_TYPEDEFS --ignore MACRO_ARGUMENTS \
		--ignore BLOCK_COMMENT_STYLE --ignore LINE_CONTINUATIONS \
		--ignore LEADING_SPACE --ignore TRAILING_SPACE -f $(addsuffix /*.[ch], .)
	@echo "has bin checked with checkpatch!"
else
	@echo "ERROR: Please provide a static code analysis tool with CHECK_TOOL variable"
	@exit 1
endif


.PHONY: clean

# Ціль для очищення згенерованих файлів
clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/*.a
	rm -rf $(BUILD_DIR)/*.so
	rm -rf $(BUILD_DIR)/$(TARGET)

# Створення директорії build
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
