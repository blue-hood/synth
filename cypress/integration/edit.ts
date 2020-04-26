/// <reference types="cypress" />

describe('edit', () => {
  it('校正を通過できる', () => {
    cy.visit('');
    cy.get('header button').click();
    cy.get('.MuiDrawer-root.MuiDrawer-modal').contains('メモを追加').click();
    cy.contains('校正を通過しました！');
  });

  /*it('メッセージを表示できる', () => {
    cy.visit('');
    cy.get('header button').click();
    cy.get('.MuiDrawer-root.MuiDrawer-modal').contains('メモを追加').click();
    cy.get('[contenteditable="plaintext-only"]').type('私は私は').blur();
    cy.get('.MuiBox-root.MuiBox-root-316 svg').click();
    cy.contains('一文に二回以上利用されている助詞 "は" がみつかりました。');
  });*/
});
