(function ($) {
    function pum_claims_convert_currency() {
        var currency_id = $('#edit-currency').val();
        var amount = parseFloat($('#edit-amount').val());
        $('#euro_amount').html('0,00');
        if (currency_id > 0 && amount != NaN) {
            $.ajax({
                url: Drupal.settings.pum_claims.currencyConvertUrl,
                method: "GET",
                data: {
                    currency_id: currency_id,
                    amount: amount
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
        }
    };

}(jQuery));