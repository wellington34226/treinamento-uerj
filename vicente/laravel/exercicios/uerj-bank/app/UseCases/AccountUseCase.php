<?php
namespace App\UseCases;

use App\Repositories\AccountRepository;

class AccountUseCase {
  public function __construct(private AccountRepository $accountRepository){}

  public function getByUserId($userId){
    $account = $this->accountRepository->getByUserId($userId);
    return $account;
  }
}
