#!/usr/bin/env python3

import sys
import os
sys.path.append("../lib")
import ctypes
import time
import numpy as np

# Encontre o diretório onde o script Python está localizado
package_dir = os.path.dirname(__file__)

# Defina o caminho completo para a biblioteca
lib_path = os.path.join(package_dir, 'lib', 'unitree_arm_interface.cpython-310-x86_64-linux-gnu.so')

# Verifique se a biblioteca existe
if not os.path.exists(lib_path):
    print(f"Erro: Não foi possível encontrar a biblioteca no caminho: {lib_path}")
    sys.exit(1)

# Adicione o diretório contendo a biblioteca ao caminho de bibliotecas dinâmicas
os.environ['LD_LIBRARY_PATH'] = os.path.dirname(lib_path) + ':' + os.environ.get('LD_LIBRARY_PATH', '')

# Tente carregar a biblioteca
lib = ctypes.CDLL(lib_path)

# Agora você pode acessar as funções dentro da biblioteca
import unitree_arm_interface

np.set_printoptions(precision=3, suppress=True)

print("Press ctrl+\ to quit process.")

arm =  unitree_arm_interface.ArmInterface(hasGripper=True)
armState = unitree_arm_interface.ArmFSMState
arm.loopOn()

# 1. highcmd_basic : armCtrlInJointCtrl
arm.labelRun("forward")
arm.startTrack(armState.JOINTCTRL)
jnt_speed = 1.0
for i in range(0, 1000):
    # dp = directions * speed; include 7 joints
    arm.jointCtrlCmd([0,0,0,-1,0,0,-1], jnt_speed)
    time.sleep(arm._ctrlComp.dt)

# 2. highcmd_basic : armCtrlByFSM
arm.labelRun("forward")
gripper_pos = 0.0
jnt_speed = 2.0
arm.MoveJ([0.5,0.1,0.1,0.5,-0.2,0.5], gripper_pos, jnt_speed)
gripper_pos = -1.0
cartesian_speed = 0.5
arm.MoveL([0,0,0,0.45,-0.2,0.2], gripper_pos, cartesian_speed)
gripper_pos = 0.0
arm.MoveC([0,0,0,0.45,0,0.4], [0,0,0,0.45,0.2,0.2], gripper_pos, cartesian_speed)

# 3. highcmd_basic : armCtrlInCartesian
arm.labelRun("forward")
arm.startTrack(armState.CARTESIAN)
angular_vel = 0.3
linear_vel = 0.3
for i in range(0, 1000):
    arm.cartesianCtrlCmd([0,0,0,0,0,-1,-1], angular_vel, linear_vel)
    time.sleep(arm._ctrlComp.dt)

arm.backToStart()
arm.loopOff()