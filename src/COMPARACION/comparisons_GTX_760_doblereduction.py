
#%%
import numpy as np 
import matplotlib.pyplot as plt

#%%
#Formacion de los parametros para realizar los txt para realizar las comparaciones

mesh_size = 2 ** np.arange(4,12)
num_blocks = 2 ** np.arange(10)
num_iter = 10 ** np.arange(2,6)

shape=np.shape(num_blocks)
#%%
#np.savetxt("mesh_size.txt", mesh_size, fmt="%s")
#np.savetxt("num_blocks.txt", num_blocks, fmt="%s")
#np.savetxt("num_iter.txt", num_iter, fmt="%s")


#%%
#se fueron realizando las corridas y se lleno a mano estos datos

time_c = np.array([ 2.01297e-05,6.89077e-05,0.00016829,0.000549431,0.00219535,0.00884031,0.0355933,0.141666])

time_cu_1 = np.array([ 4.73404e-05,0.00011924,0.00044137,0.00175939,0.00638656,0.0250995,0.0996618,0.397149,])

time_cu_2 = np.array([ 3.31187e-05,7.55405e-05,0.000239708,0.000847502,0.00327183,0.0130574,0.0522236,0.208849,])

time_cu_4 = np.array([1.94311e-05,4.4322e-05,0.00014256,0.000480139,0.0018075,0.00715914,0.028614,0.114293,])

time_cu_8 = np.array([2.75898e-05,3.43704e-05,8.84199e-05,0.000291181,0.00108296,0.00426223,0.0170034,0.0678945,])

time_cu_16 = np.array([2.496e-05,2.92087e-05,7.64322e-05,0.000232482,0.00087182,0.00340977,0.0136387,0.0547571,])

time_cu_32 = np.array([3.29304e-05,3.34597e-05,7.48992e-05,0.000234241,0.00084049,0.00326935,0.0130502,0.0520459,])

time_cu_64 = np.array([3.28493e-05,3.39508e-05,7.0951e-05,0.000232441,0.00083966,0.00326515,0.0129782,0.0518361,])

time_cu_128 = np.array([4.26507e-05,4.58097e-05,7.76911e-05,0.000242901,0.000850251,0.00328134,0.0129949,0.0518656,])

time_cu_256 = np.array([4.73404e-05,4.12893e-05,7.59411e-05,0.000255198,0.000869472,0.00329118,0.0130559,0.0518351,])   

time_cu_512 = np.array([3.8538e-05,5.05686e-05,0.000101008,0.000281,0.000871079,0.00328556,0.013005,0.0520528,])

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
plt.title('Comparision of C and CUDA C GTX 760 double reduction',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Time of execution (s)',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('time_c_cuda_doblereduction.png')
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
plt.title('Performance of CUDA on C GTX 760 double reduction',fontsize=14)
plt.xlabel('Cuadrangular Mesh Size',fontsize=14)
plt.ylabel('Performance \%',fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xscale('log') 
plt.grid(True)
plt.savefig('performance_cuda_cobre_c_doblereduction.png')
plt.close
