# 🤖 LineFollower & WallFollower Robot

This repository contains the code, documentation, and setup for a **Line Follower & Wall Follower Robot** — a dual-mode autonomous mobile robot that can follow lines on the ground and avoid obstacles using wall detection.

The system combines sensor feedback with real-time motor control to enable intelligent navigation without manual control.

---

## 🎯 Project Overview

The robot supports **two autonomous modes**:

### 🟦 Line Follower Mode  
Follows a predefined line (usually black tape) on the ground using IR/line sensors.

### 🟩 Wall Follower Mode  
Uses proximity sensors to follow a wall at a set distance — useful for maze navigation or corridor tracking.

These modes make it ideal for robotics learning, competitions, and real-world navigation challenges.

---

## 🛠️ Hardware Components

> *(Update this list based on your exact build if needed)*

| Component | Purpose |
|-----------|---------|
| Microcontroller (Arduino / ESP32 / STM32) | Robot brain & control |
| Line Sensors (IR array / reflectance sensors) | Detects line on the ground |
| Ultrasonic / Proximity Sensors | Measures wall distance |
| DC Motors + Wheels | Drive motion |
| Motor Driver (L298N, TB6612, etc.) | Controls motor speed/direction |
| Chassis & Power Supply | Physical structure and power |

---

## 📌 Features

✅ Autonomous line tracking  
✅ Wall-following navigation  
✅ Modular code structure  
✅ Expandable for additional tasks (e.g., obstacle avoidance, mapping)

---

## 🚀 How It Works

### 📍 Line Follower Mode
1. Line sensors read reflectance values.
2. Controller adjusts motor speed to stay on track.
3. Robot follows the line smoothly even around turns.

### 📍 Wall Follower Mode
1. Distance sensor checks distance from wall.
2. Robot adjusts its path to maintain a constant distance.
3. Continual feedback loop ensures stable wall tracking.

---

## 🧪 Getting Started

### 📋 Prerequisites

Before building and uploading the code, make sure you have:

✔ Arduino IDE or PlatformIO  
✔ USB drivers for your microcontroller  
✔ Sensor libraries (e.g., `Ultrasonic`, `QTRSensors`, etc.)

### 💾 Installation

1. Clone the repository  
   ```bash
   git clone https://github.com/PrashilLamichhane/LineFollower_WallFollower.git
