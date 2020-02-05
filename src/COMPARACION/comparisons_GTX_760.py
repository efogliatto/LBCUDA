
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
np.savetxt("mesh_size.txt", mesh_size, fmt="%s")
np.savetxt("num_blocks.txt", num_blocks, fmt="%s")
np.savetxt("num_iter.txt", num_iter, fmt="%s")


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

time_py = np.array([ ])

#%%
prom_1 = (time_c-time_cu_1)/time_cu_1 *100
prom_2 = (time_c-time_cu_2)/time_cu_2 *100
prom_4 = (time_c-time_cu_4)/time_cu_4 *100
prom_8 = (time_c-time_cu_8)/time_cu_8 *100
prom_16 = (time_c-time_cu_16)/time_cu_16 *100
prom_32 = (time_c-time_cu_32)/time_cu_32 *100
prom_64 = (time_c-time_cu_64)/time_cu_64 *100
prom_128 = (time_c-time_cu_128)/time_cu_128 *100
prom_256 = (time_c-time_cu_256)/time_cu_256 *100 
prom_512 = (time_c-time_cu_512)/time_cu_512*100

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
plt.title('Rendimiento de CUDA sobre C GTX 760',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Performance \%',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('performance_cuda_cobre_c.png')
plt.close
