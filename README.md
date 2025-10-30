# 📊 Body Mass Index (BMI) Calculator

This is a small console application written in C that calculates the user's Body Mass Index (BMI) and determines their ideal weight range, offering a friendly, colored interface.

---

## ✨ Features

- **BMI Calculation:** Calculates BMI based on weight (kg) and height (m).  
- **Weight Classification:** Displays the weight classification (Underweight, Normal Weight, Obesity, etc.) according to the thresholds defined in the code (based on WHO standards).  
- **Ideal Weight Range:** Calculates and displays the ideal weight range in kilograms for the entered height.  
- **Interactive Interface:** Uses colors and an ASCII banner for a better visual experience in the terminal.  
- **Compatibility:** Works across different operating systems like Windows, Linux, and macOS (adaptive screen clearing).  

---

## ⬇️ Setup (Cloning the Repository)

If this project is hosted on GitHub, you can clone it to your local machine using Git:

```bash
git clone https://github.com/CodeMarcsX/BMI-Calculator.git
cd BMI-Calculator
````

---

## 🛠️ How to Compile and Run

### Prerequisites

To compile and run this program, you will need a C compiler installed on your system, such as GCC (GNU Compiler Collection) or Clang.

### Compilation

1. Save the provided source code in a file named `main.c`.
2. Open your terminal or command prompt.
3. Execute the following command to compile the program:

```bash
gcc main.c -o main
```

### Execution

After compilation, run the generated executable:

**On Linux/macOS:**

```bash
./main
```

**On Windows:**

```bash
.\main.exe
```
⚠️ Important: If the banner or special characters appear "bugged" in the terminal, first set the code page to UTF-8:
```bash
chcp 65001
```


---

## 🚀 Usage

1. The program will start with a banner and the screen will be cleared.
2. It will prompt you to enter your weight in kilograms (kg).
3. Next, it will prompt for your height in meters (m).
4. The result will be displayed, showing your BMI, classification, and ideal weight range.

**Interaction Example:**

```
=====================================
         █████╗  ███╗   ███╗██╗
         ██╔══██╗████╗ ████║██║
         ███████║██╔████╔██║██║
         ██╔══██║██║╚██╔╝██║██║
         ███████║██║ ╚═╝ ██║██║
         ╚══════╝╚═╝     ╚═╝╚═╝
=====================================
        BODY MASS INDEX
=====================================

Your weight (kg): 75
Your height (m): 1.75

Classification: Normal weight
Your BMI is 24.5
Ideal weight between 56.6 kg and 76.2 kg
