---
marp: true
paginate: true
---

# Laravel

Repositório projeto: https://github.com/vicentecalfo/uerj-laravel

_Vicente Calfo_
<small>vicentecalfo@gmail.com</small>
<small>https://www.linkedin.com/in/vicentecalfo/</small>
<small>https://github.com/vicentecalfo</small>

---

# O que é o Laravel?

O **Laravel** é um framework de desenvolvimento web em PHP, conhecido por sua elegância, simplicidade e facilidade de uso. Ele segue a arquitetura MVC (Model-View-Controller) e oferece uma ampla gama de recursos e funcionalidades pré-construídas que agilizam o processo de desenvolvimento.

---

# Principais características do Laravel:

- Sintaxe expressiva e intuitiva.
- Arquitetura MVC.
- Recursos pré-construídos para facilitar o desenvolvimento.
- Rotas amigáveis.
- Sistema de gerenciamento de banco de dados.
- Mecanismo de templates.
- Autenticação de usuários.
- Segurança.
- Cache.

---

# Outros detalhes

- O Laravel possui uma comunidade ativa e suporte contínuo;
- Oferece documentação detalhada;
- Variedade de pacotes adicionais (conhecidos como "Laravel Packages") e uma comunidade engajada;
- Amplamente utilizado;
- Usado para o desenvolvimento de aplicações de todos os portes.

---

# Instalando o Composer no Windows

- https://getcomposer.org/Composer-Setup.exe

Após a instalação, reiniciar todos os terminais abertos e digitar <code> composer -V </code>

## O que é o Composer

- Uma ferramenta de gerenciamento de dependências para projetos em PHP.
- Permite que você defina as dependências do seu projeto em um arquivo composer.json, onde você pode listar as bibliotecas que seu projeto precisa para funcionar corretamente.

---

# Instalação do Laravel

- Ir no <code>php.ini</code> da instalção do PHP, na <code>linha 965</code> e mudar para <code>extension=php_zip.dll</code>

- Incluir também no <code>php.ini</code> na <code>linha 966</code>: <code>extension=php_fileinfo.dll</code>

```bash

composer create-project laravel/laravel uerj-bank

```

O projeto será criado em uma pasta <code>uerj-bank</code> ("nome do projeto").

---

# Plugins úteis do VSCode

- Laravel Blade Snippets
- Laravel Exrra Intellisense

---

# Entendendo a estrutura de uma aplicação Laravel

- <code>app</code> -> Arquivos da "nossa" aplicação.
- <code>config</code> -> Arquivos de configuração (app, database, mail).
- <code>database</code> -> Migrations (interface para criar, alterar e editar tabelas do BD), Seeds para popular tabelas do BD e Factories usado para popular as tabelas.
- <code>public</code> -> Fica o index.php (roteadores).
- <code>resources</code> -> Assets, views e arquivos de tradução (i18n).
- <code>tests</code> -> Teste unitários da aplicação.
- <code>vendor</code> -> Pacotes de terceiros que usamos na aplicação.
- <code>.env</code> -> Variáveis de ambiente da aplicação.

---

# Iniciando a aplicação

```bash

php artisan serve

ou

php artisan serve --port=8080

```

- Acessar: http://localhost:8000/

---

# Onde ficam as rotas?

pasta -> "routes" -> arquivo "web.php"

```php
<?php
use Illuminate\Support\Facades\Route;
/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});
```

---

# Criando Controles (controllers)

|Este comando irá gerar arquivos na pasra **app/Http/Controllers**.

**php artisan make:controller NOMEController**

exemplos:

**php artisan make:controller LoginController**

**php artisan make:controller DashboardController**

OBSERVAÇÃO: Não é obrigatório mas é indicado usar o sufixo _controller_, para os nomes do arquivos.

---

# Criando Controles

- LoginController
- DashboardController
- PixController
- BankStatement

---

# Criando os métodos

No arquivo DashboardController.php

```php
<?php
namespace App\Http\Controllers;
use Illuminate\Http\Request;
class DashboardController extends Controller
{
    public function index(){
        $title = "Dashboard";
        echo $title;
    }
}
```

---

# Registrando a rota

Arquivo: routes/web.php

```php
<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\DashboardController;


Route::get('/', function () {
    return view('welcome');
});

Route::get('/dashboard', [DashboardController::class, 'index']);
```

---

# Lidando com Request

```php
<?php
// arquivo DashboardController.php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class DashboardController extends Controller
{
    public function index(Request $request){
        $title = "Dashboard";
        echo $title;
    }
}
```

**Request** -> Podemos pegar detalhes da requisição como: query string, inputs de formulários.

---

# Lidando com Response

```php
<?php
// arquivo DashboardController.php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class DashboardController extends Controller
{
    public function index(Request $request){
        $title = "Dashboard";
        return $title;
    }
}
```

---

# Response

- O Laravel possui um recurso chamado "echo" implícito, que facilita o retorno de objetos ou arrays como resposta, convertendo-os automaticamente para o formato JSON. Isso é especialmente útil ao criar APIs, pois permite uma comunicação eficiente entre o servidor e o cliente.

- Além disso, o Laravel oferece controle total sobre os códigos de status HTTP e os cabeçalhos das respostas. Podemos definir o código de status apropriado para cada situação, como 200 para sucesso ou 404 para recurso não encontrado.

---

# Exemplo de return com objetos

```php
<?php
namespace App\Http\Controllers;
use Illuminate\Http\Request;
class DashboardController extends Controller
{
    public function index(){
       $teste =[
        'nome' => 'Vicente',
        'idade' => 40,
        'preferencias' => [
            'js', 'ts', 'php', 'laravel', 'react'
        ]
        ];
        return $teste;
    }
}
```

**OBSERVAÇÃO**: Após o teste voltar o arquivo ao que era.

---

# Trabalhando na camada de visão (view)

- criar um arquivo de visão (html) na pasta: \*resources/views/dashboard/index.blade.php

```php
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Dashboard</title>
</head>
<body>
    dashboard
</body>
</html>
```

---

# Atualizando o controller

```php
<?php

namespace App\Http\Controllers;
use Illuminate\Http\Request;
class DashboardController extends Controller
{
    public function index(){
        $title = "Dashboard";
        return view('dashboard/index');
    }
}
```

---

# Preparando as páginas

- criar as pastas **images** e **css** dentro de **public**;
- dentro da pasta **css**, criar o arquivo **app.css**;
- copiar as images pra dentro de images (logo, bg e etc...);
- criar em **views** a pasta **layouts** e dentro criar o arquivo **layout-sidebar.blade.php**.

---

# Arquivo App.css

```css
* {
  box-sizing: border-box !important;
}
html {
  overflow: hidden;
}
.app {
  width: 100vw;
  height: 100vh;
  background-color: #fff;
  display: grid;
  grid-template-columns: 240px 1fr;
  gap: 10px;
  overflow: hidden !important;
}
.app aside,
.app main {
  padding: 40px 40px;
}
.app aside .logo {
  display: block;
  margin: 0 auto;
}
.app main {
  background-color: #f2f2f2;
}
.extrato {
  display: grid;
  grid-template-columns: 1fr auto;
  gap: 20px;
  align-items: center;
}
```

---

# Arquivo Layout

1/2

```php
<?php
$menu = [
    array(
        "title" => "Acesso Rápido",
        "items" => array(
            "dashboard" => "Dashboard",
            "extrato" => "Extrato"
        )
    ),
    array(
        "title" => "Área do PIX",
        "items" => array(
            "pix" => "Pagar"
        )
    ),
    array(
        "title" => "Administração",
        "items" => array(
            "sair" => "Sair",

        )
    )
];
?>

```

---

# Arquivo Layout

2/2

```php
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{{ $title ?? "UERJ Bank" }}</title>
    <link rel="stylesheet" href="./css/app.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.0/jquery.min.js"></script>
    <script src="https://igorescobar.github.io/jQuery-Mask-Plugin/js/jquery.mask.min.js"></script>
</head>
<body>
    <div class="app">
        <aside>
            <img src="./images/UERJ-Bank-logo.png" class="logo" />
            <nav class="menu mt-6">
                @foreach ($menu as $parentItem)
                <p class="menu-label">{{$parentItem["title"]}}</p>
                <ul class="menu-list is-primary">
                    @foreach ($parentItem["items"] as $path => $label)
                    <li><a href="{{$path}}" class="{{$activePath == $path ? 'is-active' : ''}}">{{$label}}</a></li>
                    @endforeach
                </ul>
                @endforeach
            </nav>
        </aside>
        <main>
            {{ $slot }}
        </main>
    </div>
</body>
</html>
```

---

# Atualizando o Dashboard Controller

```php
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class DashboardController extends Controller
{
    public function index(Request $request){
        $title = "Dashboard";
        return view('dashboard/index',[
            'activePath' => $request->path()
        ]);
    }
}
```

---

# Preparando as páginas de PIX e Extrato

Dentro de views criar:

- bankStatement/index.blade.php
- pix/index.blade.php
- login/index.blade.php

Incluir o método **index**, mudando o $title e o caminho para o **template**.

```php

 public function index(Request $request){
        $title = "Entrar";
        return view('login/index',[
            'activePath' => $request->path()
        ]);
    }
```

---

# Registrar as URLs - web.php

```php
<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\DashboardController;
use App\Http\Controllers\PixController;
use App\Http\Controllers\LoginController;
use App\Http\Controllers\BankStatementController;


Route::get('/', function () {
    return view('welcome');
});

Route::get('/dashboard', [DashboardController::class, 'index']);
Route::get('/pix', [PixController::class, 'index']);
Route::get('/login', [LoginController::class, 'index']);
Route::get('/extrato', [BankStatementController::class, 'index']);
```

---

# Atualizando os VIEWS

Copiar e colar o código abaixo nos arquivos de views: pix, bankStatement e login.

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    Pix
@endcomponent
```

---

# Melhorando o layout-sidebar

- criar 2 arquivos **head.blade.php** e **footer.blade.php**;
- atualizar o arquivo **layout-sidebar**:

```php
<?php // $menu = [ ...] <- o objeto do menu mantém?>
@include('layouts/head')
<div class="app">
    <aside>
        <img src="./images/UERJ-Bank-logo.png" class="logo" />
        <nav class="menu mt-6">
            @foreach ($menu as $parentItem)
                <p class="menu-label">{{ $parentItem['title'] }}</p>
                <ul class="menu-list is-primary">
                    @foreach ($parentItem['items'] as $path => $label)
                        <li><a href="{{ $path }}"
                                class="{{ $activePath == $path ? 'is-active' : '' }}">{{ $label }}</a></li>
                    @endforeach
                </ul>
            @endforeach
        </nav>
    </aside>
    <main>
        {{ $slot }}
    </main>
</div>
@include('layouts/footer')
```

---

# Criando o arquivo head.blade.php

```php
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{{ $title ?? "UERJ Bank" }}</title>
    <link rel="stylesheet" href="./css/app.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.0/jquery.min.js"></script>
    <script src="https://igorescobar.github.io/jQuery-Mask-Plugin/js/jquery.mask.min.js"></script>
</head>
<body>
```

---

# Criando o arquivo footer.blade.php

```php
</body>
</html>
```

---

# Criando um layout sem nenhuma marcação

## layout-raw.php

```php
@include('layouts/head')
{{ $slot }}
@include('layouts/footer')
```

---

# Criando o arquivo de login e permitindo CSS customizado

```php
@component('layouts/layout-raw', ['customCss' => 'login'])
<div class="login">
    <div class="card p-4">
        <div class="card-content">
            <div class="content">
                <img src="images/UERJ-Bank-logo.png" class="logo" />
                <h1 class="title is-4 has-text-centered">Acesse sua conta!</h1>
                <form action="entrar" method="post">
                    <div class="columns">
                        <div class="column">
                            <div class="control">
                                <input class="input" type="text" name="email" placeholder="E-mail">
                            </div>
                        </div>
                    </div>
                    <div class="columns">
                        <div class="column">
                            <div class="control">
                                <input class="input" type="password" name="password" placeholder="Senha">
                            </div>
                        </div>
                    </div>
                    <div class="columns">
                        <div class="column">
                            <div class="control">
                                <button class="button is-link is-fullwidth" type="submit">Entrar</button>
                            </div>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>
@endcomponent
```

---

# Atualizando os arquivos de layout para permitir CSS customizados

Fazer essa atualização no **layout-raw.blade.php** e no **layout-sidebar.blade.php**.

```php

// mudar o @include('layouts/head') pelo código abaixo:

@if (isset($customCss))
    @include('layouts/head', ['customCss' => $customCss] )
@else
    @include('layouts/head')
@endif

```

---

# Atualizando o head

```php
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{{ $title ?? "UERJ Bank" }}</title>
    <link rel="stylesheet" href="./css/app.css">
    @if(isset($customCss))
    <link rel="stylesheet" href="./css/{{$customCss}}.css">
    @endif
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.0/jquery.min.js"></script>
    <script src="https://igorescobar.github.io/jQuery-Mask-Plugin/js/jquery.mask.min.js"></script>
</head>
<body>
```

---

# Preparando outros templates - Dashboard

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    <div class="columns">
        <div class="column">
            <h2 class="title">Painel Inicial</h2>
        </div>
      </div>
      <div class="columns">
        <div class="column">
          <div class="card">
            <div class="card-content">
              <div class="extrato">
                <span>
                  <h3 class="title is-3">8000</h3>
                  <small>Seu limite atual é de 1000.</small>
                </span>
                <span>
                  <a href="extrato" class="button is-link">Ver extrato</a>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
@endcomponent
```

---

# Teste DB

- Atualizar o .env com os dados de acesso do banco de dados.

```
DB_CONNECTION=mysql
DB_HOST=vicenteblog.mysql.dbaas.com.br
DB_PORT=3306
DB_DATABASE=vicenteblog
DB_USERNAME=vicenteblog
DB_PASSWORD=EeMeV280618@5e

```

---

# Acessando o Banco

```php

use Illuminate\Support\Facades\DB;

class DashboardController extends Controller
{

    public function testDB(Request $request){
        $data = DB::select('select * from user');
        //$data = DB::select('select * from user where id = :id', ['id' => 1]);
        //var_dump($data);
        return $data;
    }
}


```

---

# Criando _casos de uso_ e respositórios

Criar pastas **UseCases** e **Repositories** dentro da pasta **app**

Criar um arquivo chamado AccountUseCase.php dentro da pasta UseCases

```php

<?php

namespace App\UseCases;

use Illuminate\Support\Facades\DB;

class AccountUseCase
{
    public function getByUserId($userId){
       $data = DB::select('select * from account where userId = :userId', ['userId' => $userId]);
       return $data[0];
    }

}

```

---

# Testando o UseCase -> DashboardController.php

```php
<?php

namespace App\Http\Controllers;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use App\UseCases\AccountUseCase;

class DashboardController extends Controller
{

    public function __construct(
        private AccountUseCase $accountUseCase,
    ){}

    public function index(Request $request){
        $title = "Dashboard";
        $account = $this->accountUseCase->getByUserId(1); //1 vicente, 15 alexandre, 17 pedro, 19 matheus, 16 paulo
        return view('dashboard/index',  array(
            'activePath' => $request->path(),
            'account' => $account
        ));
    }

}
```

---

# Template

dashboard/index.blade.php

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    <div class="columns">
        <div class="column">
            <h2 class="title">Painel Inicial</h2>
        </div>
      </div>
      <div class="columns">
        <div class="column">
          <div class="card">
            <div class="card-content">
              <div class="extrato">
                <span>
                  <h3 class="title is-3">{{ $account->balance }}</h3>
                  <small>Seu limite atual é de {{ $account->accountLimit }}.</small>
                </span>
                <span>
                  <a href="extrato" class="button is-link">Ver extrato</a>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
@endcomponent

```

---

# Caso de uso de Usuário - UserUseCase.php

```php
<?php

namespace App\UseCases;

use Illuminate\Support\Facades\DB;

class UserUseCase
{
    public function getById($id){
       $data = DB::select('select * from users where id = :id', ['id' => $id]);
       return $data[0];
    }

}
```

---

# Criando Repositório - UserRepository.php

```php
<?php

namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class UserRepository{

    public function getById($id){
       $data = DB::select('select * from users where id = :id', ['id' => $id]);
       return $data[0];
    }

}

```

---

# Refatorando caso de uso - UserUseCase.php

```php

<?php

namespace App\UseCases;
use App\Repositories\UserRepository;

class UserUseCase{

public function __construct(
    private UserRepository $userRepository
){}


    public function getById($id){
       $user = $this->userRepository->getById($id);
       return $user;
    }

}

```

---

# Refatorando controller

```php

<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\UseCases\AccountUseCase;
use App\UseCases\UserUseCase;

class DashboardController extends Controller
{

    public function __construct(
        private AccountUseCase $accountUseCase,
        private UserUseCase $userUseCase
    ){}

    public function index(Request $request){
        $title = "Dashboard";
        $account = $this->accountUseCase->getByUserId(1);
        $user = $this->userUseCase->getById(1);
        return view('dashboard/index',  array(
            'activePath' => $request->path(),
            'account' => $account,
            'user' => $user
        ));
    }

}


```

---

# Refatorando visão (template) - dashboard/index

```php

@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    <div class="columns">
        <div class="column">
            <h2 class="title">Olá, {{$user->firstName}} {{ $user->lastName }}</h2>
        </div>
      </div>
      <div class="columns">
        <div class="column">
          <div class="card">
            <div class="card-content">
              <div class="extrato">
                <span>
                  <h3 class="title is-3">{{ $account->balance }}</h3>
                  <small>Seu limite atual é de {{ $account->accountLimit }}.</small>
                </span>
                <span>
                  <a href="extrato" class="button is-link">Ver extrato</a>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
@endcomponent

```

---

# Ajustando o caso de uso de "conta"

Criar repositório de conta -> AccountRepository.php

```php
<?php

namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class AccountRepository{

    public function getByUserId($userId){
       $data = DB::select('select * from account where userId = :userId', ['userId' => $userId]);
       return $data[0];
    }

}
```

---

# Refatorando caso de uso de conta -> AccountUseCase.php

```php
<?php

namespace App\UseCases;
use App\Repositories\AccountRepository;

class AccountUseCase
{

    public function __construct(
        private AccountRepository $accountRepository
    ){}

    public function getByUserId($userId){
        $account = $this->accountRepository->getByUserId($userId);
        return $account;
    }

}
```

---

# Melhorando a visão (dashboard/index)

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    <div class="columns">
        <div class="column">
            <h2 class="title">Olá, {{$user->firstName}} {{ $user->lastName }}</h2>
        </div>
      </div>
      <div class="columns">
        <div class="column">
          <div class="card">
            <div class="card-content">
              <div class="extrato">
                <span>
                  <h3 class="title is-3">{{ $account->balance }} <small class="has-text-grey">VCC</small></h3>
                  <small>Seu limite atual é de {{ $account->accountLimit }} <small class="has-text-grey">VCC</small>.</small>
                  <br />
                  <small class="has-text-grey is-size-7">* VCC (Vicente Calfo Coins)</small>
                </span>
                <span>
                  <a href="extrato" class="button is-link">Ver extrato</a>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
@endcomponent
```

---

# Criando caso de uso e repositório de extrato

Criar o arquivo de repositório

```php
<?php

namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class BankStatementRepository{

    public function getByUserId($userId){
       $data = DB::select('select * from transaction where userId = :userId', ['userId' => $userId]);
       return $data;
    }

}
```

---

# Criando o caso de uso -> BankStatementUseCase.php

```php

<?php

namespace App\UseCases;
use App\Repositories\BankStatementRepository;

class BankStatementUseCase
{


    public function __construct(
        private BankStatementRepository $bankStatementRepository
    ){}

    public function getByUserId($userId){
       $bankStatement = $this->bankStatementRepository->getByUserId($userId);
       return $bankStatement;
    }

}
```

---

# Testando a consulta

BankStatementController.php

```php
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\UseCases\BankStatementUseCase;

class BankStatementController extends Controller
{


    public function __construct(
        private BankStatementUseCase $bankStatementUseCase,
    ){}

    public function index(Request $request){
        $title = "Extrato";
        $bankStatement = $this->bankStatementUseCase->getByUserId(1);
        var_dump($bankStatement);
        return view('bankStatement/index',[
            'activePath' => $request->path()
        ]);
    }
}

```

---

# Criando um componente para o Extrato

```
php artisan make:component BankStatementTable
```

Serão criados 2 arquivos:

- app\View\Components\BankStatementTable.php
- resources\views\components\bank-statement-table.blade.php

---

# Usando o component

bank-statement-table.blade.php

```php

<div>
    Tabela de extrato
</div>
```

bankStatement/index.blade.php

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
    <x-bank-statement-table />
@endcomponent
```

---

# Passando os dados para o componente

App/View/Components/BankStatementTable.php

```php
<?php

namespace App\View\Components;

use Closure;
use Illuminate\Contracts\View\View;
use Illuminate\View\Component;

class BankStatementTable extends Component
{
    public $bankStatement;
    /**
     * Create a new component instance.
     */
    public function __construct($bankStatement)
    {
        $this->bankStatement = $bankStatement;
    }

    /**
     * Get the view / contents that represent the component.
     */
    public function render(): View|Closure|string
    {
        return view('components.bank-statement-table');
    }
}

```

---

# Enviando pro template os dados

BankStatementController.php

```php
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\UseCases\BankStatementUseCase;

class BankStatementController extends Controller
{


    public function __construct(
        private BankStatementUseCase $bankStatementUseCase,
    ){}

    public function index(Request $request){
        $title = "Extrato";
        $bankStatement = $this->bankStatementUseCase->getByUserId(1);
        return view('bankStatement/index',[
            'activePath' => $request->path(),
            'bankStatement' => $bankStatement
        ]);
    }
}

```

---

# Atualizando o template do extrato

bankStatement/index.blade.php

```php
@component('layouts/layout-sidebar')
    @slot('activePath') {{ $activePath }} @endslot
        <h2 class="title">Últimas 10 Transações</h2>
    <x-bank-statement-table :bankStatement="$bankStatement"/>
@endcomponent
```

---

# Testando a passagem dos dados para o componente

components/bank-statement-table.blade.php

```php
<div>
    @foreach ($bankStatement as $transaction)
        <p>{{ $transaction->source }}</p>
    @endforeach
</div>

```

---

# Construindo a tabela base

components/bank-statement-table.blade.php

```php
<?php

$typeTags = [
    'OUTCOME_PIX' => [
        'class' => 'tag is-danger is-light',
        'label' => 'PIX Enviado',
    ],
    'INCOME_PIX' => [
        'class' => 'tag is-success is-light',
        'label' => 'PIX Recebido',
    ],
];

?>

<table class="table is-striped is-fullwidth">
    <thead>
        <tr>
            <th>Data</th>
            <th>Valor (VCC)</th>
            <th>Fonte</th>
            <th>Transação</th>
        </tr>
    </thead>
    <tbody>
        @foreach ($bankStatement as $transaction)
            <tr>
                <td>{{ date("d/m/Y", $transaction->date) }}</td>
                <td>{{ $transaction->amount }}</td>
                <td>{{ $transaction->source }}</td>
                <td>
                    <span class="{{ $typeTags[$transaction->type]["class"] }}">
                        {{ $typeTags[$transaction->type]["label"] }}
                    </span>
                </td>
            </tr>
        @endforeach
    </tbody>
</table>

```

---

# Redirecionando rotas

routes/web.php

```php

Route::redirect('/', '/dashboard');

```

---

# Passando paramêtros

routes/web.php

```php

Route::get('/pix/{name}', [PixController::class, 'index']);

```

PixController.php

```php
<?php
{
    public function index(Request $request, string $name = ''){
        $title = "PIX";
        return view('pix/index',[
            'activePath' => $request->path(),
            'name' => $name
        ]);
    }
}
```

---

# Template PIX

pix/index.blade.php

```php
    @component('layouts/layout-sidebar')
        @slot('activePath') {{ $activePath }} @endslot
        <h1>Pix</h1>
        <h2>{{ $name }}</h2>
    @endcomponent
```

---

# Atual erro 404

Tornando opcional o parâmetro.

```php
Route::get('/pix/{name?}', [PixController::class, 'index']);
```

---

# Ajustando a quebra de layout

head.blade.php

```php
<!DOCTYPE html>
<html>
<head>
    <base href="/">
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{{ $title ?? "UERJ Bank" }}</title>
    <link rel="stylesheet" href="./css/app.css">
    @if(isset($customCss))
    <link rel="stylesheet" href="./css/{{$customCss}}.css">
    @endif
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.0/jquery.min.js"></script>
    <script src="https://igorescobar.github.io/jQuery-Mask-Plugin/js/jquery.mask.min.js"></script>
</head>
<body>
```

---

# Autenticação - LoginController.php

```php
    public function auth(Request $request){
        $credentials = $request->validate([
            'email' => ['required','email'],
            'password' => ['required'],
        ],
        [
            'email.required' => 'O e-mail é obrigatório.',
            'email.email' => 'O e-mail não é válido.',
            'password.required' => 'A senha é obrigatória.'
        ]
    );
        if(Auth::attempt($credentials)){
            $request->session()->regenerate();
            return redirect('/dashboard');
        }else{
            return redirect()->back()->with('error', 'Credenciais inválidas');
        }
    }
```

---

# Autenticação (sair) - LoginController.php

```php
    public function logout(Request $request){
        Auth::logout();
        $request->session()->invalidate();
        $request->session()->regenerateToken();
        return redirect('/login');
    }
```

---

# Template Login - login/index.blade.php

```php

<h1 class="title is-4 has-text-centered">Acesse sua conta!</h1>
                @if($error = Session::get('error') )
                    {{$error}}
                @endif
                @if($errors->any())
                    @foreach ( $errors->all() as $error )
                        {{ $error }}
                    @endforeach
                @endif
                <form action="{{ route('login.auth') }}" method="post">
                    @csrf

```
---

# Criando nomes para as rotas e protegendo

```php

Route::redirect('/', '/login');
Route::get('/dashboard', [DashboardController::class, 'index'])->middleware('auth');
Route::get('/pix/{name?}', [PixController::class, 'index'])->middleware('auth');

Route::get('/login', [LoginController::class, 'index'])->name('login');
Route::post('/auth', [LoginController::class, 'auth'])->name('login.auth');
Route::get('/sair', [LoginController::class, 'logout']);

Route::get('/extrato', [BankStatementController::class, 'index'])->middleware('auth');

```

---

# Pegando parâmetros com POST

```php

$request->post('my_param');

```
---

# Publicando
```php
$ php composer install
$ php composer dumpautoload -o
$ php artisan config:cache
$ php artisan route:cache
```
A partir de agora, sempre que você implantar, ou seja, atualizar o diretório do projeto, será necessário refletir todas as alterações no diretório project/public/ para o diretório www/, exceto pelo arquivo www/index.php, que já está configurado acima para incluir os caminhos corretos.

