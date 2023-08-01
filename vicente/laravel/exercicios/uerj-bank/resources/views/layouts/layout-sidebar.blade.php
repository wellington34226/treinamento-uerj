<?php
$menu = [
    [
        'title' => 'Acesso Rápido',
        'items' => [
            'dashboard' => 'Dashboard',
            'extrato' => 'Extrato',
        ],
    ],
    [
        'title' => 'Área do PIX',
        'items' => [
            'pix' => 'Pagar',
        ],
    ],
    [
        'title' => 'Administração',
        'items' => [
            'sair' => 'Sair',
        ],
    ],
];
?>
@if (isset($customCss))
  @include('layouts/head', ['customCss' => $customCss] )
@else
  @include('layouts/head')
@endif
<div class="app">
    <aside>
        <img src="/images/UERJ-Bank-logo.png" class="logo" />
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
