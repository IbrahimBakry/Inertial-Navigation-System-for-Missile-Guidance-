## **Inertial Navigation System for Missile Guidance** 🚀🧭  

### **✨ Core Concept**  
A **frameless inertial system** designed for short-duration missile operations (~200 sec) that calculates:  
- **Orientation** (Euler angles Φ, θ, Ψ)  
- **Velocity** (Vx, Vy, Vz)  
- **Position** (X, Y, Z)  
...using only onboard accelerometer and gyroscope data—**no external references**.  

---

## **🔧 Key Components**  
### **1️⃣ Attitude Calculation (Quaternions)**  
- Solves time-varying differential equations for quaternion propagation (`Q̇ = ½ Q ⨂ Ω`).  
- Uses **Runge-Kutta** for numerical integration.  
- Normalizes quaternions to prevent drift:  
  ```math  
  |Q| = √(Q₁² + Q₂² + Q₃² + Q₄²)  
  Qᵢ = Qᵢ / |Q|  
  ```  

### **2️⃣ Transformation Matrix (B)**  
Converts body-frame data to inertial frame:  
```math  
B = [ ... ]  // 3x3 matrix from quaternions  
```  

### **3️⃣ Velocity & Position**  
- **Absolute acceleration** = Specific force (A) + Gravity (φ).  
- Integrates to get velocity:  
  ```math  
  V = V₀ + ∫(A + φ)dt  
  ```  
- Gravity modeled with Earth’s harmonics (J₂, J₄ terms).  

### **4️⃣ Euler Angles**  
Extracted from quaternions:  
```math  
θ = -arcsin(2(Q₄Q₂ + Q₁Q₃))  
Φ = arcsin(2(Q₄Q₃ - Q₁Q₂)/cosθ  
Ψ = arcsin(2(Q₂Q₃ - Q₁Q₄)/cosθ  
```  

---

## **⚡ Why It’s Innovative**  
- **Self-contained**: No GPS or external signals.  
- **High-speed processing**: Optimized for short-duration flights.  
- **Robust math**: Quaternions avoid gimbal lock; Runge-Kutta ensures precision.  

---

## **🛠️ Skills Demonstrated**  
- **Advanced kinematics**: Quaternion calculus, coordinate transforms.  
- **Numerical methods**: Runge-Kutta integration.  
- **Real-time systems**: Low-latency processing for missile guidance.  

---

## **🎯 Applications**  
- **Missile guidance systems**  
- **Autonomous drones**  
- **Spacecraft attitude control**  

**#Aerospace #GuidanceSystems #Quaternions #STEM** 🔥  
