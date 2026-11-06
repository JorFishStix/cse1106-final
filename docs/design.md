#DESIGN

- Ask user "Use Default Temp Range ?"
- if Yes, set range to 68 to 76 inclusive
- if no, prompt user to enter a new range.

- Get Temperature readings
  
- If TEMP is within 68 and 76 inclusive,
-    display NORMAL status
-    Warning LED should not turn on
- if TEMP is below 68 and over 76F,
-    display WARNING status
-    Warning LED should turn on
  
-    Save temperature readings and their statuses to a file
