#%% con mecom07

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

time_c = np.array([3.06821e-06, ])

time_cu_1 = np.array([])

time_cu_2 = np.array([])

time_cu_4 = np.array([])

time_cu_8 = np.array([])

time_cu_16 = np.array([])

time_cu_32 = np.array([])

time_cu_64 = np.array([)

time_cu_128 = np.array([])   

time_cu_256 = np.array([])

time_cu_512 = np.array([])

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
plt.title('Comparacion de C y CUDA C GTX xxx',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Time of execution (s)',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('time_c_cuda_xxx.png')
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
plt.title('Rendimiento de CUDA sobre C GTX xxx',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Performance \%',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('performance_cuda_cobre_c_xxx.png')
plt.close

