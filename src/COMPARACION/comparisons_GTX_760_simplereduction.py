
#%%
import numpy as np 
import matplotlib.pyplot as plt

#%%
#Formacion de los parametros para realizar los txt para realizar las comparaciones

mesh_size = 2 ** np.arange(4,13)
num_blocks = 2 ** np.arange(10)
num_iter = 10 ** np.arange(2,6)

shape=np.shape(num_blocks)
#%%
#np.savetxt("mesh_size.txt", mesh_size, fmt="%s")
#np.savetxt("num_blocks.txt", num_blocks, fmt="%s")
#np.savetxt("num_iter.txt", num_iter, fmt="%s")


#%%
#se fueron realizando las corridas y se lleno a mano estos datos

time_c = np.array([ 2.44284e-06,9.69696e-06,2.07779e-05,6.4043e-05,0.000254973,0.00105161,0.00413887,0.0166056,0.0663194])

time_cu_1 = np.array([ 1.2639e-05,2.4935e-05,5.70021e-05,0.00021192,0.000785126,0.00302436,0.0120047,0.0478569,0.191371])

time_cu_2 = np.array([1.1503e-05,1.64812e-05,3.44491e-05,0.00011915,0.00039936,0.0015842,0.00625284,0.0248858,0.0994628])

time_cu_4 = np.array([1.54872e-05,1.76539e-05,2.48611e-05,6.34909e-05,0.000238652,0.00084589,0.0033491,0.0133551,0.0533814])

time_cu_8 = np.array([1.439e-05,1.15151e-05,1.85411e-05,4.2165e-05,0.000135486,0.000493061,0.00193364,0.00771224,0.030743])

time_cu_16 = np.array([1.23889e-05,1.25101e-05,0.015942,3.2793e-05,9.60958e-05,0.000344314,0.00133482,0.00530269,0.0211572])

time_cu_32 = np.array([1.03579e-05,1.33371e-05,1.66209e-05,3.64928e-05,9.4173e-05,0.000361327,0.00131006,0.00520369,0.0207734])

time_cu_64 = np.array([1.00241e-05,1.6398e-05,1.64649e-05,3.4946e-05,0.000105162,0.000336664,0.00130831,0.00519814,0.02074])

time_cu_128 = np.array([1.6773e-05,1.53608e-05,1.5121e-05,3.48659e-05,0.000106731,0.000339256,0.00131026,0.00519624,0.0207662])   

time_cu_256 = np.array([1.47901e-05,1.2908e-05,1.7499e-05,3.7652e-05,0.000107454,0.000338482,0.00131096,0.00521994,0.0207651])

time_cu_512 = np.array([1.4734e-05,1.5965e-05,1.75018e-05,3.86848e-05,0.000107951,0.00036502,0.00131293,0.0052077,0.0207714])

time_py_1 = np.array([4.65727e-05,7.3247e-05,0.000178638,0.000602665,0.00227318,0.00823726,0.0319054,0.127004,0.50661 ])

time_py_2 = np.array([4.43268e-05,5.80978e-05,0.000113652,0.000326431,0.0010656,0.00405179,0.0162745,0.0645982,0.256975 ])

time_py_4 = np.array([4.20856e-05,4.95887e-05,7.91168e-05,0.000189748,0.000557544,0.00210381,0.00831499,0.0330819,0.13221 ])

time_py_8 = np.array([4.08912e-05,4.14658e-05,5.80549e-05,0.000122433,0.000315595,0.001137,0.00441913,0.0175629,0.0700855 ])

time_py_16 = np.array([4.19211e-05,3.97944e-05,4.95791e-05,9.28092e-05,0.00020185,0.000680604, 0.00259262,0.0102468,0.0410308 ])

time_py_32 = np.array([4.45032e-05,4.02045e-05,4.51612e-05,7.98988e-05,0.000160725,0.000519016,0.00195418,0.00768237,0.0305965 ])

time_py_64 = np.array([4.35758e-05,4.03476e-05,4.53019e-05,7.16019e-05,0.000139055,0.000434217,0.00161738,0.00635362,0.0254497 ])

time_py_128 = np.array([4.23598e-05,4.06432e-05,4.35615e-05,7.20239e-05,0.000128264,0.000400155,0.00158705,0.00593013,0.0231288 ])

time_py_256 = np.array([4.33493e-05,4.01855e-05,4.43912e-05,7.61127e-05,0.00012851,0.000399578,0.00147916,0.00579614,0.0232974 ])

time_py_512 = np.array([4.11439e-05,4.30417e-05,4.64201e-05,7.55596e-05,0.000127473,0.000401514,0.00148567,0.00581523,0.0231366 ])

#%%
prom_1 = time_c /time_cu_1 
prom_2 = time_c /time_cu_2 
prom_4 = time_c /time_cu_4 
prom_8 = time_c /time_cu_8 
prom_16 = time_c /time_cu_16 
prom_32 = time_c /time_cu_32 
prom_64 = time_c /time_cu_64 
prom_128 = time_c /time_cu_128
prom_256 = time_c /time_cu_256
prom_512 = time_c /time_cu_512

prom_1_py = time_c /time_py_1 
prom_2_py = time_c /time_py_2 
prom_4_py = time_c /time_py_4 
prom_8_py = time_c /time_py_8 
prom_16_py = time_c /time_py_16 
prom_32_py = time_c /time_py_32 
prom_64_py = time_c /time_py_64 
prom_128_py = time_c /time_py_128
prom_256_py = time_c /time_py_256
prom_512_py = time_c /time_py_512

#%%
plt.figure()
plt.plot(mesh_size,time_c,label='C')
plt.plot(mesh_size,time_cu_1,label='CUDA C 1')
plt.plot(mesh_size,time_cu_2,label='CUDA C 2')
plt.plot(mesh_size,time_cu_4,label='CUDA C 4')
plt.plot(mesh_size,time_cu_8,label='CUDA C 8')
plt.plot(mesh_size,time_cu_16,label='CUDA C 16')
plt.plot(mesh_size,time_cu_32,label='CUDA C 32')
plt.plot(mesh_size,time_cu_64,label='CUDA C 64')
plt.plot(mesh_size,time_cu_128,label='CUDA C 128')
plt.plot(mesh_size,time_cu_256,label='CUDA C 256')
plt.plot(mesh_size,time_cu_512,label='CUDA C 512')

plt.legend()
plt.title('Comparacion de C y CUDA C GTX 760',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Time of execution (s)',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.yscale('log') 
plt.grid(True)
plt.savefig('time_c_cuda.png')
plt.close

#%%
plt.figure()
plt.plot(mesh_size,prom_1,label='CUDA C 1')
plt.plot(mesh_size,prom_2,label='CUDA C 2')
plt.plot(mesh_size,prom_4,label='CUDA C 4')
plt.plot(mesh_size,prom_8,label='CUDA C 8')
plt.plot(mesh_size,prom_16,label='CUDA C 16')
plt.plot(mesh_size,prom_32,label='CUDA C 32')
plt.plot(mesh_size,prom_64,label='CUDA C 64')
plt.plot(mesh_size,prom_128,label='CUDA C 128')
plt.plot(mesh_size,prom_256,label='CUDA C 256')
plt.plot(mesh_size,prom_512,label='CUDA C 512')

plt.legend()
plt.title('Spyder de CUDA sobre C GTX 760',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Spyder',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('performance_cuda_cobre_c.png')
plt.close
