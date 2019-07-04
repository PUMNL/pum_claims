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

            $('.form-item-distance-km').hide();

            $('#pum-claims-line-form #edit-type')
              .change(function() {
                //#3946: Show distance field when KM-allowance is selected
                if($('#pum-claims-line-form #edit-type').val() == Drupal.settings.pum_claims.km_allowance) {
                  $('.form-item-distance-km').show();
                } else {
                  $('.form-item-distance-km').hide();
                }

                //#3820: Show description when claim line type is selected
                $.each(Drupal.settings.pum_claims.claim_type_description.values, function(key, claim_type) {
                  if (claim_type.value == $('#edit-type').val()){
                    $('#expense_type_description').text(claim_type.description);
                    if(claim_type.description != undefined && claim_type.description.length > 0) {
                      $('#expense_type_description').show();
                    } else {
                      $('#expense_type_description').hide();
                    }
                  }
                });
              }).change();
        }
    };

}(jQuery));