;; -*- lexical-binding: t -*-

;; this add `include' additional paths to flycheck (linter) and
;; company-mode (auto-completion) correctly fetch the headers of the project.
((nil . ((eval . (let* ((src-path (concat (projectile-project-root) "src/"))
                        (include-path (list src-path))
                        (clang-argument (list
                                         (format "-I%s"
                                                 src-path))))

                   ;; install:
                   ;; sudo snap install universal-ctags (apt version is outdated)
                   ;; sudo update-alternatives --install /usr/bin/ctags ctags /snap/bin/universal-ctags 1111
                   (setq-local projectile-tags-command "ctags -Re -f \"%s\" %s src/")
                   (setq-local flycheck-clang-include-path include-path)
                   (setq-local company-clang-arguments clang-argument))))))
