(function ($) {
    function pum_claims_convert_currency() {
        var currency_id = $('#edit-currency').val();
        var amount = parseFloat($('#edit-amount').val());
        var expense_date = $('#edit-expense-date-datepicker-popup-0').val();
        $('#euro_amount').html('0.00');
        if (currency_id > 0 && amount != NaN && expense_date.length > 0) {

            $.ajax({
                url: Drupal.settings.pum_claims.currencyConvertUrl,
                method: "GET",
                data: {
                    currency_id: currency_id,
                    amount: amount,
                    conversion_date: expense_date
                },
                dataType: "html",
                success: function (data) {
                    $('#euro-amount').html(data);
                }
            });
        }

    }

    Drupal.behaviors.claims = {
        attach: function (context, settings) {
            $('#edit-expense-date-datepicker-popup-0', context).change(pum_claims_convert_currency);
            $('#edit-currency', context).change(pum_claims_convert_currency);
            $('#edit-amount', context).change(pum_claims_convert_currency);
            $('.line-amount-eur').hover(
                function() {
                    jQuery(this).children('.line-log').css('display', '');
                },
                function () {
                    jQuery(this).children('.line-log').css('display', 'none');
                }
            );

            $('.helpbutton').hover(function() {
              $('#description_help').show();
            });

            $('.helpbutton').mouseout(function() {
              $('#description_help').hide();
            });

            //#3946: Hide distance field when KM-allowance is not selected
            $('.form-item-distance-km').hide();

            $('#pum-claims-line-form #edit-type')
              .change(function() {
                if($('#pum-claims-line-form #edit-type').val() == Drupal.settings.pum_claims.km_allowance) {
                  $('.form-item-distance-km').show();
                } else {
                  $('.form-item-distance-km').hide();
                }
              })
              .ready(function() {
                if($('#pum-claims-line-form #edit-type').val() == Drupal.settings.pum_claims.km_allowance) {
                  $('.form-item-distance-km').show();
                } else {
                  $('.form-item-distance-km').hide();
                }
              });
        }
    };

}(jQuery));