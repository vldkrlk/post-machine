# Turing Machine Commands  

## Commands  
- `1` - Writes to the cell  
- `0` - Erases the cell  
- `<` - Moves one step left  
- `>` - Moves one step right  
- `?` - Conditional jump:  
  - If the cell **is not marked**, jumps to the **first jump point**  
  - Else, jumps to the **second jump point**  
- `!` - Stops the machine  

## Jump Types  
1. `""` - Empty jump moves to the next command  
2. `"1"` - Jumps to the **first command**  
3. `"3,4"` - Conditional jump for `?`:  
   - If the cell is **marked**, jumps to `4`  
   - Else, jumps to `3`  

## Stop Conditions  
1. Stops after the `!` command  
2. Stops when the **command pointer** goes out of range  
3. Stops when the program encounters an **incorrect command**  

---

# Команди машини Тюрінга  

## Команди  
- `1` - Запис у комірку  
- `0` - Стирання комірки  
- `<` - Крок ліворуч  
- `>` - Крок праворуч  
- `?` - Умовний перехід:  
  - Якщо комірка **не позначена**, стрибок до **першої точки переходу**  
  - Інакше, стрибок до **другої точки переходу**  
- `!` - Зупинка машини  

## Типи стрибків  
1. `""` - Порожній стрибок, що переходить до наступної команди  
2. `"1"` - Перехід до **першої команди**  
3. `"3,4"` - Умовний стрибок для `?`:  
   - Якщо комірка **позначена**, стрибок до `4`  
   - Інакше, стрибок до `3`  

## Умови зупинки  
1. Зупинка після команди `!`  
2. Зупинка, якщо **вказівник команди** виходить за межі  
3. Зупинка, якщо програма зустрічає **некоректну команду**  

