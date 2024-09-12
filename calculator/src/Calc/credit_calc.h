#ifndef SRC_CREDIT_CALC_H_
#define SRC_CREDIT_CALC_H_

#include "s21_helper.h"

/**
  @brief Функция расчета аннуиентного платежа
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double calculate_annuitet(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета начисленых процентов
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double annuitet_percent(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета долга с процентами
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double annuitet_dolg_proc(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета первого платежа для дифференцированных платежей
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double dif_month_min(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета последнего платежа для дифференцированных платежей
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double dif_month_max(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета переплаты для дифференцированных платежей
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double dif_pereplat(double tel_cred, double proc_cred, int month_cred);
/**
  @brief Функция расчета полной выплаты для дифференцированных платежей
  @param tel_cred тело кредита
  @param proc_cred процентная ставка
  @param month_cred период на который выдан кредит
*/
double dif_total(double tel_cred, double proc_cred, int month_cred);
#endif