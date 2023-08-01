<?php
namespace App\UseCases;

use App\Repositories\UserRepository;

class UserUseCase {
  public function __construct(private UserRepository $userRepository){}

  public function getById($id){
    $user = $this->userRepository->getById($id);
    return $user;
  }
}
