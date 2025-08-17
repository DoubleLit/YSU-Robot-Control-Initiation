# 🔧 YSU机器人控制学习仓库 | 仪器科学与技术学硕
**目标导师：张宇（视觉伺服控制） | 就业方向：工业机器人控制算法工程师**  
[![ROS2](https://img.shields.io/badge/ROS2-Humble-brightgreen)](https://docs.ros.org/)
[![C++](https://img.shields.io/badge/C++-17-blue)](https://isocpp.org/)

## 🚩 学习路径（2025.8.17-8.28）
| 日期       | 进展                          | 成果链接                                                                 |
|------------|------------------------------|------------------------------------------------------------------------|
| 2025.08.18 | ROS2 Humble安装               | [验证截图](2_ROS_Projects/gazebo_ur5_simulation/images/install_success.png) |
| 2025.08.20 | C++链表题解                   | [206反转链表](1_Cpp_Core_Skills/Leetcode_Solutions/206_Reverse_Linked_List.cpp) |
| 2025.08.23 | Gazebo机械臂轨迹控制          | [Demo视频](2_ROS_Projects/gazebo_ur5_simulation/videos/trajectory_demo.mp4) |
| 2025.08.26 | STM32-ROS姿态传感器通信       | [代码实现](2_ROS_Projects/stm32_ros_interface/) |

## ⚡ 核心项目展示
### 1. STM32-ROS多传感器接口
- **技术栈**：STM32F4 + MPU6050 + ROS2 serial包
- **创新点**：硬件滤波（卡尔曼） + 时间戳同步  
- **实物演示**：  
  ![传感器模块](2_ROS_Projects/stm32_ros_interface/images/hardware_setup.jpg)

### 2. Gazebo视觉伺服仿真
- 复现张宇论文《Adaptive Sliding Mode Control for Visual Servoing》(IEEE T-IE 2024)  
- **简化实现**：位置控制模式下的目标跟踪  
  ```bash
  ros2 launch ur5_vision_servo servo.launch.py
  ```

## 📚 精读文献
1. [Zhang Y. et al. - Adaptive Visual Servoing with Dynamic Compensation (IEEE T-IE 2024)](3_References/Papers/Visual_Servo_Zhang.pdf)  
   - **复现计划**：9月移植至实验室焊接机器人平台
