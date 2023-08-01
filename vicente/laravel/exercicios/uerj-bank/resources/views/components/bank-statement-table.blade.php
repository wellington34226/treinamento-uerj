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
          <span class="{{ $typeTags[$transaction->type]['class'] }}">
            {{ $typeTags[$transaction->type]["label"] }}
          </span>
        </td>
      </tr>
    @endforeach
  </tbody>
</table>
