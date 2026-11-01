cmake_minimum_required(VERSION 4.3)
project(Team_Assigment_Algpro C)

set(CMAKE_C_STANDARD 11)

#add_executable(Team_Assigment_Algpro
#        ACCA/tugas2a.c
#        ACCA/tugas2b.c
#        ACCA/tugas2c.c
#        DCCA/soal1.c
#        DCCA/soal2_fixed.c)


add_executable(TugasACCA_2A ACCA/tugas2a.c)
add_executable(TugasACCA_2B ACCA/tugas2b.c)
add_executable(TugasACCA_2C ACCA/tugas2c.c)
add_executable(TugasDCCA_1 DCCA/question_1.c)
add_executable(TugasDCCA_2 DCCA/question_2_fixed.c)

# DCCA 3 (Week 9 - Sesi 22 - R3)
add_executable(TugasDCCA3_Hanoi "DCCA 3/src/hanoi.c")
add_executable(TugasDCCA3_Factorial "DCCA 3/src/factorial.c")
add_executable(TugasDCCA3_SearchSiswa "DCCA 3/answer/search_siswa.c")

# ACCA 2 (Week 10 - Proyek Praktikum 2)
add_executable(TugasACCA2 "ACCA 2/src/main.c")

