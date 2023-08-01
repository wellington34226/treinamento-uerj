@component('layouts/layout-raw', ['customCss' => 'login'])
@slot('title') {{ $title }} @endslot
<div class="login">
  <div class="card p-4">
    <div class="card-content">
      <div class="content">
        <img src="images/UERJ-Bank-logo.png" class="logo" />
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
