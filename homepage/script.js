
document.addEventListener('DOMContentLoaded', function() {
    var pageLinks = document.querySelectorAll('a.nav-link');
    pageLinks.forEach(function(link) {
      link.addEventListener('click', function(event) {
        event.preventDefault();
        var targetPage = this.getAttribute('href');
        alert('Navigating to ' + targetPage);
        window.location.href = targetPage;
      });
    });
  });
