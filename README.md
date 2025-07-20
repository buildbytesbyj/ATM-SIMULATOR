# 🏧 ATM Simulator Console App in C++

A simple command-line ATM simulator built in C++. This project allows users to perform basic banking operations like checking balance, depositing, and withdrawing money — all with PIN verification and file-based persistent storage.

## 💡 Features

- 🔐 PIN-based access (Default PIN: `1234`)
- 💰 Persistent balance using `balance.txt`
- 📥 Deposit money
- 💸 Withdraw money with balance check
- 📄 Console-based UI with menus
- ⚙️ Modular code with file handling

## 🖥️ How It Works

- When you run the program for the first time, it creates `balance.txt` and sets the balance to ₹10,000.
- Each transaction updates the file so the balance is saved even after you exit.
- The PIN must be entered correctly to proceed.

## 📂 File Structure
