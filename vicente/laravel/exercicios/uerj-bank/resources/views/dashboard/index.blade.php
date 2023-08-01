@component('layouts/layout-sidebar')
  @slot('activePath') {{ $activePath }} @endslot
  @slot('title') {{ $title }} @endslot
  <div class="columns">
    <div class="column">
        <h2 class="title">Olá, {{ $user->firstName }} {{ $user->lastName }}</h2>
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
