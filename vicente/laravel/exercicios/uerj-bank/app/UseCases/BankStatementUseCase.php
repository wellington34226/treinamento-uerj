<?php

namespace App\UseCases;
use App\Repositories\BankStatementRepository;

class BankStatementUseCase{
  public function __construct(private BankStatementRepository $bankStatementRepository){}

  public function getByUserId($userId){
    $bankStatement = $this->bankStatementRepository->getByUserId($userId);
    return $bankStatement;
  }
}
