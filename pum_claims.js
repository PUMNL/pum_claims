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
            $('#expense_type_description').hide();

            $('#pum-claims-line-form #edit-type')
              .change(function() {
                //#3946: Show distance field when KM-allowance is selected
                if($('#pum-claims-line-form #edit-type').val() == Drupal.settings.pum_claims.km_allowance) {
                  $('.form-item-distance-km').show();
                } else {
                  $('.form-item-distance-km').hide();
                }

                //#3820: Show description when claim line type is selected
                $('#expense_type_description').text('');
                $('#expense_type_description').hide();
                $('#pum-claims-line-form #expense_type_description').css('background-color','#FFFFFF');

                $.each(Drupal.settings.pum_claims.claim_type_description.values, function(key, claim_type) {
                    if(claim_type.value == $('#pum-claims-line-form #edit-type').val()){
                      $('#expense_type_description').text(claim_type.description);
                      $('#expense_type_description').show();
                      $('#pum-claims-line-form #expense_type_description').css('background-color','#E5DEFF');
                    }
                });
              }).change();

            $('#remuneration_policy').click(function(){
              var win = '';
              var rep_found = false;

              for (var role in Drupal.settings.pum_claims.user.roles) {
                if(Drupal.settings.pum_claims.user.roles[role] == 'Representative'){
                    rep_found = true;
                }
              }

              if (rep_found == true){
                win = window.open(Drupal.settings.pum_claims.pum_claims_linkremunerationpolicyreps_en, '_blank');
              } else if(Drupal.settings.pum_claims.site_language == 'en' | Drupal.settings.pum_claims.site_language == 'fr' | Drupal.settings.pum_claims.site_language == 'es' | Drupal.settings.pum_claims.site_language == 'ar' | Drupal.settings.pum_claims.site_language == 'ru'){
                win = window.open(Drupal.settings.pum_claims.pum_claims_linkremunerationpolicy_en, '_blank');
              } else if(Drupal.settings.pum_claims.site_language == 'nl'){
                win = window.open(Drupal.settings.pum_claims.pum_claims_linkremunerationpolicy_nl, '_blank');
              } else {
                win = window.open(Drupal.settings.pum_claims.pum_claims_linkremunerationpolicy_en, '_blank');
              }
              if (win) {
                  //Browser has allowed it to be opened
                  win.focus();
              } else {
                  //Browser has blocked it
                  //alert('Please allow popups for this website');
              }
            });

            $('#pum-claims-line-form #edit-distance-km').keypress(function (e) {
              var allowedChars = '0123456789';
              function contains(stringValue, charValue) {
                  return stringValue.indexOf(charValue) > -1;
              }
              var invalidKey = e.key.length === 1 && !contains(allowedChars, e.key) || e.key === '.' && contains(e.target.value, '.');
              if(invalidKey) {
                e.preventDefault();
              }
            });
            $('#pum-claims-line-form #edit-amount').keypress(function (e) {
              var allowedChars = '0123456789.';
              function contains(stringValue, charValue) {
                  return stringValue.indexOf(charValue) > -1;
              }
              var invalidKey = e.key.length === 1 && !contains(allowedChars, e.key) || e.key === '.' && contains(e.target.value, '.');
              if(invalidKey) {
                e.preventDefault();
              }
            });
        }
    };

}(jQuery));