# Cheat the history!

## merge vs rebase
1. **merge**
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/ab83d0de-d414-4b00-94df-96155a52c877)

2. **rebase**
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/39141ef7-ba06-42cd-a2b8-0e23989b5d24)
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/88c6352b-d560-4e4a-aee0-7dfb8e0c8355)
  * **git rebase master**
  * **git adog** : we see that the history is now 'flat' and the **HEAD** of the **master** is in the **WRONG** position
  * we have to **git merge second-branch**
  * **git adog** : now we have the **HEAD** in the proper place
  * _Observation: the merge was created in 'fast-forward' mode, meaning that no additional commit was created, but the **HEAD** marker was moved_
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/8b89cb3d-6948-4a6b-a5d5-316c75e55fe3)


